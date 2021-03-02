#include "Simple_window.h"
#include "Graph.h"

	
int main() 
try {
	using namespace Graph_lib;
	

	Simple_window win{Point{100,100}, 600, 400, "My window"};



	Axis xa{Axis::x, Point{30,300}, 310, 12, "x axis"};
	win.attach(xa);
	win.wait_for_button();



	Axis ya{Axis::y, Point{30,300}, 310, 12, "y axis"};
	win.attach(ya);
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_green);
	win.wait_for_button();



	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);
	r.set_fill_color(Color::yellow);
	win.wait_for_button();



	Function sine{sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);
	win.wait_for_button();



	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	win.attach(poly);
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	poly.set_style(Line_style(Line_style::dash,4));
	win.wait_for_button();



	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.wait_for_button();



	Text t{Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.wait_for_button();



	Image ii {Point{10,10},"chonk.jpg"};
	win.attach(ii);
	ii.move(100,200);
	win.wait_for_button();



	Circle c {Point{100,200},50};
	win.attach(c);
	win.wait_for_button();



	Ellipse e {Point{100,200}, 75,25};
	win.attach(e);
	e.set_color(Color::dark_red);
	win.wait_for_button();


	Mark m {Point{100,200},'x'};
	win.attach(m);
	win.wait_for_button();



	ostringstream oss;

	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	win.attach(sizes);
	win.wait_for_button();


}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "Something went wrong" << endl;
    keep_window_open();
}
