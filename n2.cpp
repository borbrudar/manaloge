#include <iostream>
#include <vector>

int rec(const std::vector<int>& field, int n, int m, int &count, int startX, int startY){
    if(startX + count > m || startY + count > n) return count - 1;
    
    for(int i = count; i >= 0; i--){
        if(field[startX + startY *m + i * m + count] == 0) return count - 1;
    }
    for(int i = 0; i <= count; i++){
        if(field[startX + startY*m + count * m + i] == 0) return count - 1;
    }

    count++;
    count = rec(field, n,  m, count, startX, startY);
    
    return count;    
};

int najvecji(const std::vector<int>& field, int n, int m) {
    
    int maxCount = 0, count = 0;
    
    for(int x = 0; x < m;x++){
        for(int y = 0; y < n;y++){
            if(field[x + y * m] == 0) continue;
            count = 1;
            count = rec(field,n,m,count,x,y) + 1;
            if(count > maxCount) maxCount = count;
        }
    }
    
    
    return maxCount;
};


int main(){
	std::vector<int> field{
	    0,0,0,0,0,0,
	    1,1,1,1,0,0,
	    1,1,1,1,0,0,
	    1,1,1,1,0,0,
	    1,1,1,1,0,0
	};
	std::cout << "Najvecji kvadrat ima stranico " + std::to_string(najvecji(field,5,6)) << std::endl;
}
