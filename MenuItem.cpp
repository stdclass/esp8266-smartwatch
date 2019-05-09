
#include "MenuItem.h"


MenuItem::MenuItem(String _title, bool _selectable)
{
    title = _title;
    selectable = _selectable;
    selected = false;
}

void MenuItem::setSelected(bool _selected)
{
    selected = _selected;
}

void MenuItem::render(U8G2 dsp, int posY)
{
    dsp.setCursor(10, posY);
    dsp.print(title);

    if( selected ){
        if( selectable ){
            dsp.setFont(u8g2_font_open_iconic_all_1x_t);
            dsp.drawStr(0, posY - 1, "o");
            dsp.setFont(u8g2_font_mercutio_basic_nbp_t_all);
        }else{
            dsp.drawUTF8(2, posY, "·");
        }
    }
}

bool MenuItem::isFixed()
{
    return false;
}
