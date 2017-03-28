#ifndef buttons_hpp
#define buttons_hpp

//Buttons-Class will be a singly linked list of buttons.
class Buttons
{
public:
  Buttons();

private:

};

//Button-Class will be a singly linked list of points of a convex polygon navigated in a clockwise order. (It might work with concaves.)
class Button
{
public:
  Button();

private:

  //A point merely holds x,y and next point and is a private member of Button-Class.
  class Point
  {
  public:
    Point(int xi, int yi, Point* tnext);

    int x;
    int y;
    Point* next;
  };

};



#endif /* buttons_hpp */