#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }


int main() 
try {

int n_points = 400;
int xscale = 30;
int yscale = 30;

Simple_window win{Point{100,100},1280,720,"ch12_exc"};
win.wait_for_button();


Rectangle rect {Point{200,200},50,100};
rect.set_color(Color::blue);
win.attach(rect);
win.set_label("ch12_exc_1");


Polygon poly;
poly.add(Point{300,200});
poly.add(Point{350,200});
poly.add(Point{350,300});
poly.add(Point{300,300});
poly.set_color(Color::red);
win.attach(poly);
win.wait_for_button();


Rectangle howdy {Point{100,100},100,30};
win.attach(howdy);
win.set_label("ch12_exc_2");

Text text {Point{125,120}, "Howdy!"};
win.attach(text);
win.wait_for_button();

Lines f;
f.add(Point{350,370},Point{500,370});
f.add(Point{425,370},Point{425,570});
f.add(Point{375,470},Point{475,470});
f.set_style(Line_style(Line_style::solid,10));
f.set_color(Color::green);
win.set_label("ch12_exc3");
win.attach(f);

Lines j;
j.add(Point{185,370},Point{315,370});
j.add(Point{250,370},Point{250,570});
j.add(Point{250,570},Point{200,570});
j.add(Point{200,570},Point{200,540});
j.set_style(Line_style(Line_style::solid,10));
j.set_color(Color::cyan);
win.attach(j);
win.wait_for_button();


int tic_tac_size = 360;
int tic_tac_grid = 120;

win.set_label("ch12_exc4");

Lines grid;

for(int x = tic_tac_grid; x <= tic_tac_size; x += tic_tac_grid)
	grid.add(Point(x,0),Point(x,tic_tac_size));
for(int y = tic_tac_grid; y <= tic_tac_size; y += tic_tac_grid)
	grid.add(Point(0,y),Point(tic_tac_size,y));

win.attach(grid);

Vector_ref<Rectangle> vr;
int width = 120;

for (int i = 0; i < 3; ++i) // sor
    {
        for (int j = 0; j < 3; ++j) // oszlop
        {
            vr.push_back(new Rectangle({i*120,j*120},width,width));
            int last = vr.size()-1;

            if( last % 2 == 0)
                vr[last].set_fill_color(Color::red);
            else 
                vr[last].set_fill_color(Color::white);

            win.attach(vr[last]);
        }
    }
win.wait_for_button();

win.set_label("ch12_exc5");

int f_x_max = (x_max()/4)*3;
int f_y_max = (y_max()/3)*2;

Rectangle rectangle(Point{1100,550},f_x_max,f_y_max);
rectangle.set_color(Color::red);
rectangle.set_style(Line_style(Line_style::solid,14));
win.attach(rectangle);

win.wait_for_button();

/*

win.set_label("ch12_exc6");

Rectangle very_big_rect{Point{120,120},2000,2000};
win.attach(very_big_rect);


Simple_window very_big_win{Point{100,100},3840,2160};
very_big_win.attach(very_big_rect);
very_big_win.wait_for_button();

win.wait_for_button();
*/

win.set_label("ch12_exc7");

int haz_magassag = 300;
    int haz_szelesseg = 600;
    Rectangle haztest {Point{600,200},haz_szelesseg, haz_magassag};
    win.attach(haztest);


    Polygon hazteto;
    hazteto.add(Point(600,200));
    hazteto.add(Point(900,50));
    hazteto.add(Point(1200,200));
    win.attach(hazteto);


    int ajto_magassag = 150;
    int ajto_szelesseg = 100;
    Rectangle ajto {Point {850,350}, ajto_szelesseg, ajto_magassag};
    win.attach(ajto);

    Circle kilincs {Point{875,435}, 7};
    win.attach(kilincs);


    int ablak_magassag = 100;
    int ablak_szelesseg = 100;

    Rectangle ablak1 {Point{700,300},ablak_szelesseg,ablak_magassag};		
    win.attach(ablak1);

    Lines ablak_keret_1; 
    ablak_keret_1.add(Point{750,300},Point{750,400});
    ablak_keret_1.add(Point{700,350},Point{800,350});		
    win.attach(ablak_keret_1);

    
    Rectangle ablak2 {Point{1000,300},ablak_szelesseg,ablak_magassag};
    win.attach(ablak2);

    Lines ablak_keret_2;
    ablak_keret_2.add(Point{1050,300},Point{1050,400});
    ablak_keret_2.add(Point{1000,350},Point{1100,350});
    win.attach(ablak_keret_2);


    Rectangle kemeny {Point{1050,50}, 50, 125};
    win.attach(kemeny);

win.wait_for_button();



Circle c1 {Point{300,150},100};
c1.set_style(Line_style(Line_style::solid,5));
c1.set_color(Color::blue);
win.set_label("ch12_exc8");
win.attach(c1);

Circle c2 {Point{480,150},100};
c2.set_style(Line_style(Line_style::solid,5));
c2.set_color(Color::black);
win.attach(c2);

Circle c3 {Point{660,150},100};
c3.set_style(Line_style(Line_style::solid,5));
c3.set_color(Color::red);
win.attach(c3);

Circle c4 {Point{382,270},100};
c4.set_style(Line_style(Line_style::solid,5));
c4.set_color(Color::yellow);
win.attach(c4);

Circle c5 {Point{568,270},100};
c5.set_style(Line_style(Line_style::solid,5));
c5.set_color(Color::green);
win.attach(c5);
win.wait_for_button();


Image ii {Point{400,300},"chonk.jpg"};
win.attach(ii);
win.set_label("ch12_exc9");
win.wait_for_button();







} catch(exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch(...) {
	cerr << "Something went wrong..." << endl;
	return 2;
}