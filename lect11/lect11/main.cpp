#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/group.hpp>
#include <nana/gui/widgets/tabbar.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/place.hpp>
#include <string>
#include <iostream>
void hello()
{
	using namespace nana;
	using namespace std;
	//Define a form.
	form fm;

	//Define a label and display a text.
	label lab{ fm, "Hello, <bold blue size=16>Nana C++ Library</>" };
	lab.format(true);

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close();
	});

	textbox input_tbx_(fm);
	string text;
	input_tbx_.move(nana::rectangle(10, 50, 100, 40));

	input_tbx_.events().key_release([&](const nana::arg_keyboard& ak) {
		
		input_tbx_.getline(0, text);
		if (ak.key == 13)    // 'Enter' apply changes
		{}
		else if (ak.key == 27)	// 'ESC' undo changes
		{//TODO: move cursor to the last of text
		}
	});


	button name_prt_btn{ fm,"Print my Name" };
	name_prt_btn.events().click([&] {//이게 & 이거 영역설정????;??
		cout << text << endl;
	
	});

	

	//Layout management
	fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><><weight=24<><button1><>><><<><tb><>><>");
	fm["text"] << lab;
	fm["button"] << btn;
	fm["button1"] << name_prt_btn;
	fm["tb"] << input_tbx_;
	fm.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}




void tab()
{
	using namespace nana;
	using namespace std;

	// form
	form fm;
	fm.caption("Hello, Nana Window!");
	fm.move(rectangle{ 0, 0, 400, 400 });

	// panel 1 for tab1
	panel<false> pnl(fm);

	group grp(pnl);
	grp.caption("Group Example");

	grp.move(rectangle{ 10, 50, 250, 100 });
	//grp.div("vert margin=10 <>><>");

	// add a button
	button btn(grp, rectangle{ 20, 50, 50, 30 });
	btn.caption(L"Quit");
	btn.events().click(API::exit);

	group grp2(pnl);
	grp2.caption("2nd group");

	grp2.move(rectangle{ 10, 150, 250, 100 });

	pnl.move(rectangle{ 10, 10, 500, 500 });

	// tab bars
	tabbar<string> tbar;
	tbar.create(fm);
	tbar.push_back(("Tab1"));
	tbar.push_back(("Tab2"));
	tbar.move(rectangle{ 5, 5, 250, 20 });
	tbar.attach(0, pnl);
	tbar.activated(0);

	fm.show();
	
	exec();
}


int main(void)
{
	hello();
}