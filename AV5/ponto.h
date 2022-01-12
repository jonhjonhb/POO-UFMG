class Ponto{
  int _x, _y;
  
  public:
  
    Ponto(int xx=0, int yy=0):_x(xx),_y(yy){ };
    Ponto& operator-- ();
    Ponto operator+ (const Ponto& pontoData) const;
    ~Ponto(){};

    // getters
    int getX()const{ return _x; }
    int getY()const{ return _y; }
    // setters
    void setX(const double x){ _x = x; }
    void setY(const double y){ _y = y; }
};