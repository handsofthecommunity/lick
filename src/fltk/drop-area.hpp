// based on http://www.fltk.org/articles.php?L770
#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>

class Fl_Window;

enum drop_area_events {
    DROP_AREA_NO_EVENT,
    DROP_AREA_CLICK,
    DROP_AREA_DROP,
    DROP_AREA_DROP_API,
};

class drop_area : public Fl_Box {
    public:
        static void callback_deferred(void *v);
        drop_area(int X, int Y, int W, int H, const char *L = 0);
        virtual ~drop_area();
        drop_area_events event();
        const char *event_text();
        int handle(int e);
        int handle_drag_event(void *event);
        void enable_drag_drop(const Fl_Window *window);
    protected:
        drop_area_events evt;
        char *evt_txt;
        int evt_len;
};
