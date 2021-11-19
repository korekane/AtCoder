#include <deque>
#include <cstdio>

using namespace std;

int main() {
    deque<int> de;
    //stackの動き
    de.push_back(1);
    de.push_back(2);
    de.push_back(3);
    printf("%d\n",de.back());
    de.pop_back();
    printf("%d\n",de.back());
    de.pop_back();
    printf("%d\n",de.back());
    de.pop_back();

    printf("\n");

    //queueの動き
    de.push_front(1);
    de.push_front(2);
    de.push_front(3);
    printf("%d\n",de.back());
    de.pop_back();
    printf("%d\n",de.back());
    de.pop_back();
    printf("%d\n",de.back());
    de.pop_back();

    return 0;
}