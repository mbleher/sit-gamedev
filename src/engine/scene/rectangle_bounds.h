// rectangle_bounds.h

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
  float d_y;
  float d_width;
  float d_height;
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

  // MEMBER FUNCTIONS
  bool doesCollide( const RectangleBounds& candidate );
    // Returns true if the object collides with candidate
};
} // End sgds namespace
} // End StevensDev namespace

#endif
