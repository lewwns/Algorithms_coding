///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignmnet #5. 
//    2. Implement function GetStudentName.
//    3. Implement function ScheduleShuttles.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_5.h") and results ("solution_5.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here


// This function should return your name.
// The name should match your name in Canvas.
void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   
   your_name.assign("Sylvia Wang");
}


int wait(std::vector<int> r, int c, int i, int k, std::vector<std::vector<int>> &table, std::vector<std::vector<int>> &check){
    
    //    std::cout << '[' << i << "][" << k << "] = "<< table[i][k] << '\n';
    
    
    
    size_t m = r.size();
    int min = 100000000;
    int time;
    int result;
    
    if(k <= 0 && i != m)
        return 100000000;
    
    if(i >= m)  // if i+s>m should return inf, but if it is the last one, should return 0.
        return 0;
    
    
    if(check[i][k] == 1)
        return table[i][k];
    
    
    
    for(int s=1; s<=c; s++){
        if(i+s-1 >= m){  // cond it here
            result = 10000000;
            break;
        }
        if(r[i+s-1] < r[i])
            result = 10000000;
        
        else{
            time = 0;
            for(int j=i; j<i+s; j++){
                time = time + (r[i+s-1] - r[j]);
            }
            
            result = time + wait(r, c, i+s, k-1, table, check);
            
        }
        
        if(result < min)
            min = result;
    }
    
    
//    if(i+s-1 < m){
        check[i][k] = 1;
        table[i][k] = min;
//    }
    return min;
    
}



bool cmp(int a, int b)
{
    return (a < b);
}


void sort_list(std::vector<int>& r)
{
    std::sort(r.begin(),r.end(),cmp);
}



//This is the function you need implement.
int ScheduleShuttles (std::vector<int> requests, int nShuttles, int capacity)
{
   // ...your code goes here...

    int ans;
    
    requests.emplace_back(0);
    
    sort_list(requests);
    
    //    nShuttles--;
    
    std::vector<std::vector<int>> table;
    table.clear();
    std::vector<int> temp2;
    temp2.clear();
    for(int i=0; i<requests.size()+5; i++){
        temp2.clear();
        for(int j=0; j<nShuttles+5; j++){
            temp2.emplace_back(0);
        }
        table.emplace_back(temp2);
    }
    std::vector<std::vector<int>> check;
    check.clear();
    std::vector<int> temp;
    temp.clear();
    for(int i=0; i<requests.size()+50; i++){
        temp.clear();
        for(int j=0; j<nShuttles+10; j++){
            temp.emplace_back(0);
        }
        check.emplace_back(temp);
    }
    
    
    
    ans = wait(requests, capacity, 1, nShuttles, table, check);
    
    return ans;
    
//   return -1;
}

