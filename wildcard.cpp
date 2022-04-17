#include <iostream>
#include <string>

using namespace std;
int cache[101][101];
string w;
string s;

bool my_cmp(int w_pos, int s_pos)
{
    int& ref = cache[w_pos][s_pos];
    if(ref != -1)
        return ref;
    while(w_pos < w.size() && s_pos < s.size() && 
            (w[w_pos] == '?' || w[w_pos] == s[s_pos])){
        ++w_pos;
        ++s_pos;
    }
    if(w_pos == w.size()){//wild card end 
        return ref = (s_pos == s.size());
    }
    if(w[w_pos] == '*'){
        for(int skip = 0; skip + s_pos <= s.size(); skip++)
        {
            if(my_cmp(w_pos+1,s_pos+skip))
                return ref = 1;
        }
    }
    return ref = 0;


}
int main()
{
   int tcase;
   cin >> tcase;

   for(int i=0; i< tcase; i++)
   {
       cin >> w;
               
       int scase;
       cin >> scase;
       for(int j=0; j < scase; j++)
       {
           cin >> s;
           memset(cache,-1,sizeof(int)*101*101);
           
           if(my_cmp(0,0))
               cout << s << endl;
       }
   }

    return 0;
}
