#include <folly/futures/Future.h>
#include <folly/executors/ThreadedExecutor.h>
#include <thread>
#include <iostream>

using namespace folly;
using namespace std;


void foo(int x) {
  // do something with x
  cout << x << endl;
}

int main()
{
    folly::ThreadedExecutor executor;
    cout << "making Promise" << endl;
    Promise<int> p;
    Future<int> f = p.getSemiFuture().via(&executor);
    auto f2 = move(f).thenValue(foo);
    cout << "Future chain made" << endl;
    cout << "fulfilling Promise" << endl;
    p.setValue(42);
    move(f2).get();
    cout << "Promise fulfilled" << endl;
    return 0;
}