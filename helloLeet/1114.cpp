// Print by order (condition_variable and mutex)
class Foo {
private:
    condition_variable cv;
    mutex m;
    int finished;
public:
    Foo() {
        finished = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        finished = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(m); // lock
        cv.wait(ul, [this]() {
            return finished == 1;
        });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        finished = 2;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this]() {
            return finished == 2;
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
