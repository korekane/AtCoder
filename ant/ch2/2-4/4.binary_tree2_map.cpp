#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main(){
    //宣言(int がキー，count char*　が値)
    map<int , const char*> m;

    //要素の追加
    m.insert(make_pair(1,"one"));
    m.insert(make_pair(10,"ten"));
    m[100] = "hundred";

    //要素の検索
    map<int, const char*>::iterator ite;
    ite = m.find(1);
    puts(ite->second);

    ite = m.find(2);
    if (ite == m.end()){
        puts("not found");
    }
    else puts(ite->second);

    //要素の削除
    m.erase(10);

    //要素全てをループ
    for (ite = m.begin(); ite != m.end(); ++ite){
        printf("%d : %s\n", ite->first, ite->second);
    }

    return 0;
}