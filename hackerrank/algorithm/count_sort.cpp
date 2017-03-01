#include <iostream>
#include <vector>
#include <string>

#define N_MAX 100

int main(){
  int n;
  std::cin >> n;

  std::vector<int> ns;
  std::vector<int> help(N_MAX,0);
  std::vector<std::string> ss;
  std::vector<std::string> sol(n, "");

  for(int i = 0; i < n; i++){
    int x;
    std::string s;
    std::cin >> x;
    std::cin >> s;

    ns.push_back(x);

    if(i+1 > n/2)
      ss.push_back(s);
    else
      ss.push_back("-");
    
    help[x] += 1;
  }

  //windowing
  for(int i=1; i < help.size(); ++i){
    help[i] = help[i-1] + help[i];
  }

  //sorting
  for(int i = ns.size()-1; i >= 0; --i){
    int idx = help[ns[i]]-1;
    help[ns[i]]--;
    sol[idx] = ss[i];
  }
  
  for(std::vector<std::string>::iterator it = sol.begin(); it != sol.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
