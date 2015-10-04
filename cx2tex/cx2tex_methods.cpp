#include <fstream>
#include <iostream>
#include <string>

#include "cx2tex.h"

using namespace std;

cx_board::cx_board() {
  board = NULL;
  rows = 0;
  cols = 0;
  fread = false;
//  in = NULL;
}

cx_board::cx_board (char *fname) {
  board = NULL;
  rows = 0;
  cols = 0;
  fread = false;

  open (fname);
}

cx_board::~cx_board() {
  int i = 0;

  if (!board) return;

  for(i = 0; i < rows; i++) {
    if (board[i] != NULL)
      delete [] board[i];
  }

  if (fread) {
    ((ifstream *)in)->close();
    delete in;
  }
}

int cx_board::open (char *fname) {
  if (fname) {
    ifstream *cx_file = new ifstream(fname, ios::in);
   
    if (!cx_file->is_open())
      return -1;

    in = cx_file;
    fread = true;
  } else in = &cin;

  return 0;
}


int cx_board::translate (void) {
  string line;
  int i = 0,
      nlines = 0;

  if (!in) return -1;

  while (getline (*in, line)) {
    if (!cols)
      cols = line.length() - 4;

    if (line[0] == '+') continue;

    if (line[0] == '|') {
      cout << "\\def \\row {" << nlines << "}\n";
      cout << "\\pgfmathsetmacro{\\py}{\\startY - \\row*\\raster}\n";

      for (i = 2; i < line.length() - 1; i++) {
        if (line[i] == ' ' && nlines % 2 == 0 && i % 2 == 0) {
          cout << "  \\def \\col {" << i - 2 << "}\n"
               << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
               << "  \\fill[white] (\\px pt, \\py pt) circle(\\padRadius);\n"
               << "  \\draw[lightgray] (\\px pt, \\py pt) circle(\\padRadius);\n";
          continue;
        }

        if (line[i] != ' ') {
          cout << "  \\def \\col {" << i - 2 << "}\n";

          switch (line[i]) {
            case '.':
              cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                   << "  \\fill[white] (\\px pt, \\py pt) circle(\\padRadius);\n"
                   << "  \\draw[lightgray] (\\px pt, \\py pt) circle(\\padRadius);\n";
              break;

            case 'o':
              cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                   << "  \\fill[white] (\\px pt, \\py pt) circle(\\padRadius);\n"
                   << "  \\draw[green] (\\px pt, \\py pt) circle(\\padRadius);\n";
              break;

            case '*':
              cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                   << "  \\fill[gray] (\\px pt, \\py pt) circle(\\padRadius);\n"
                   << "  \\draw[gray] (\\px pt, \\py pt) circle(\\padRadius);\n";
              break;

            case 'c': case 'b': case 'e': case '@':
              cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                   << "  \\fill[white] (\\px pt, \\py pt) circle(\\padRadius);\n"
                   << "  \\draw[green] (\\px pt, \\py pt) circle(\\padRadius) node[black, scale=0.5] {$"
                   << line[i] << "$};\n";
              break;

            case '+': case 'V': case 'T': case '<': case '>':
              cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                   << "  \\fill[white] (\\px pt, \\py pt) circle(\\padRadius);\n"
                   << "  \\draw[brown] (\\px pt, \\py pt) circle(\\padRadius) node[violet, scale=0.5] {$"
                   << line[i] << "$};\n";
              break;

            case '-':
              if (i % 2 == 0) 
                cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                     << "  \\fill[white] (\\px pt, \\py pt) circle(\\padRadius);\n"
                     << "  \\draw[lightgray] (\\px pt, \\py pt) circle(\\padRadius);\n";
              cout << "  \\pgfmathsetmacro{\\lpx}{\\startX + \\col*\\raster - 8 pt}\n"
                   << "  \\pgfmathsetmacro{\\rpx}{\\startX + \\col*\\raster + 8 pt}\n"
                   << "  \\draw[blue] (\\lpx pt,\\py pt) -- (\\rpx pt, \\py pt);\n";
              break;

            case '|':
              cout << "  \\pgfmathsetmacro{\\px}{\\startX + \\col*\\raster}\n"
                   << "  \\pgfmathsetmacro{\\dpy}{\\py - 8pt }\n"
                   << "  \\pgfmathsetmacro{\\upy}{\\py + 8pt }\n"
                   << "  \\draw[blue] (\\px pt,\\dpy pt) -- (\\px pt, \\upy pt);\n";
              break;

            case '/':
              cout << "  \\pgfmathsetmacro{\\lpx}{\\startX + \\col*\\raster - 9 pt}\n"
                   << "  \\pgfmathsetmacro{\\dpy}{\\py - 9pt }\n"
                   << "  \\pgfmathsetmacro{\\rpx}{\\startX + \\col*\\raster + 9 pt}\n"
                   << "  \\pgfmathsetmacro{\\upy}{\\py + 9pt }\n"
                   << "  \\draw[blue] (\\lpx pt,\\dpy pt) -- (\\rpx pt, \\upy pt);\n";
              break;

            case '\\':
              cout << "  \\pgfmathsetmacro{\\lpx}{\\startX + \\col*\\raster - 9 pt}\n"
                   << "  \\pgfmathsetmacro{\\dpy}{\\py - 9pt }\n"
                   << "  \\pgfmathsetmacro{\\rpx}{\\startX + \\col*\\raster + 9 pt}\n"
                   << "  \\pgfmathsetmacro{\\upy}{\\py + 9pt }\n"
                   << "  \\draw[blue] (\\lpx pt,\\upy pt) -- (\\rpx pt, \\dpy pt);\n";
              break;

            default: break;
          }
        }
      }
    }

    cout << "\n";

    nlines++;
  }

  rows = nlines;

  return 0;
}

