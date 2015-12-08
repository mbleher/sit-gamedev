// rectangle_bounds.h
// Boundaries of a collidable object

#ifndef INCLUDED_RECTANGLE_BOUNDS
# define INCLUDED_RECTANGLE_BOUNDS

namespace StevensDev
{
namespace sgds
{
class RectangleBounds
{
  private:
  float d_x;
    // X coordinate of the origin (left-up) point
  float d_y;
    // Y coordinate of the origin (left-up) point
  float d_width;
    // Width of the rectangle
  float d_height;
    // Height of the rectangle
  public:
  // CONSTRUCTORS
  RectangleBounds();
    // Default constructor
  RectangleBounds( float x, float y, float width, float height );
    // Constructor
  RectangleBounds( const RectangleBounds& copy );
    // Copy constructor

  // DESTRUCTOR
  ~RectangleBounds();

  // ACCESSORS
  float x() const;
  float y() const;
  float width() const;
  float height() const;

  // MUTATORS
  void setX( float x );
  void setY( float y );
  void setWidth( float width );
  void setHeight( float height );
  void setDimensions( float width, float height );
  void setPosition( float x, float y );
  void move( float x, float y );

  // MEMBER FUNCTIONS
  bool doesCollide( const RectangleBounds& candidate ) const;
    // Returns true if the object collides with candidate
};
} // End sgds namespace
} // End StevensDev namespace

#endif
