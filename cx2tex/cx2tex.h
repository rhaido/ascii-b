enum elements {
  SOLDER_ELM_LEAD = 1,
  SOLDER_ELM_LEAD_ANODE,
  SOLDER_WIRE,
  SOLDER_COLL,
  SOLDER_BASE,
  SOLDER_EMIT,
  EMPTY_PAD,
  WIRE_HORIZ,
  WIRE_VERT,
  WIRE_SL,
  WIRE_BSL,
  WIRE_PLUS
};

class cx_board {
  public:
    cx_board ();
    cx_board (char *fname);
    ~cx_board ();

    int open (char *fname = NULL);
    int translate (void);

  protected:
    char **board;
    int rows;
    int cols;
    std::istream *in;
    bool fread;
};

