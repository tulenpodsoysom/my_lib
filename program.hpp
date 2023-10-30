#include <thread>

template <class parameters, class variables>
class program
{
private:
    bool do_cycle = false; unsigned cycle_counter = 0;
public:

    parameters p;
    variables  v;

    //--- Используется для первичных задач, формирование исходного сигнала и т.п.

    virtual void init(const parameters params) { p = params;};

    //--- Используется для исполнения параллельных задач (убрать private если нужно)
//private:
    std::thread loop_thread;
    virtual void cycle_function() = 0;
    virtual void loop_function()
    {
        while (do_cycle)
        {
            cycle_function();
            cycle_counter++;
        }
    };
    void start_loop()
    {
        cycle_counter = 0;
        do_cycle = true; 
        loop_thread = std::thread(loop_function,this);
    };
    void stop_loop(){ do_cycle = false; loop_thread.join(); };

    unsigned get_cycle_counter() {return cycle_counter;};
    //---
public:

    void clear() {v = {};};
};


