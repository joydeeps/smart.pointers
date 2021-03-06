#include <boost/utility.hpp>
#include <boost/scoped_ptr.hpp>

// The point of this example is to prove that even though 
// example::implementation is an imcomplete type in translation units using
// this header, scoped_ptr< implementation > is still valid because the type is
// complete where it counts - in the implementation transalation unit where
// destruction is auctually instantiated.
//

class example : private boost::noncopyable
{
    public:
        example();
        ~example();
        void do_something();
        
    private:
        class implementation;
        boost::scoped_ptr< implementation > _imp; //hide implementation details
};
