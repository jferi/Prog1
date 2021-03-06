#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"



int main() 
try {

Simple_window win{Point{100,100},800,1000, "1_feladat"};

Lines grid;
int width_of_grid = 100;
int max_of_grid = 800;

for (int i = width_of_grid; i <= max_of_grid; i+=width_of_grid)
{
	grid.add(Point{i,0}, Point{i,max_of_grid});
	grid.add(Point{0,i}, Point{max_of_grid,i});
}
win.attach(grid);
win.set_label("2_feladat");
win.wait_for_button();


Vector_ref<Rectangle> rect_fill;
for (int i = 0; i < 8; ++i)
{
	rect_fill.push_back( new Rectangle{ Point{ i*width_of_grid, i*width_of_grid },
		 width_of_grid, width_of_grid } );
	
	rect_fill[ rect_fill.size() -1 ].set_fill_color( Color::red );
	
	win.attach( rect_fill[ rect_fill.size() -1 ] );
} 
win.set_label("3_feladat");
win.wait_for_button();


Image pic1{Point{200, 600}, "chonk_200.jpeg"};
win.attach(pic1);

Image pic2{Point{500, 100}, "chonk_200.jpeg"};
win.attach(pic2);

Image pic3{Point{0, 300}, "chonk_200.jpeg"};
win.attach(pic3);
win.set_label("4_feladat");
win.wait_for_button();



win.set_label("5_feladat");
Image chonk_100 {Point{0,0}, "chonk_100.jpeg"};
win.attach(chonk_100);
for (int i = 0; i < 8; ++i)
{
	for (int j = 0; j < 8; ++j)
	{
		win.wait_for_button();
		if (j < 7)
			chonk_100.move(100,0);
		else 
			chonk_100.move(-700,100);
			

	}
}

win.wait_for_button();




} catch(exception& e) {
	cerr << e.what() << endl;
} catch(...) {
	cerr << "Something went wrong..." << endl;
}