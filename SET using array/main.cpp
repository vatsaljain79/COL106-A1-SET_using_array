#include <iostream>
using namespace std;
#include <vector>

class SET
{
public:
    vector<int> arr;
    bool set_made = false;
    SET() {}

    int insertionbinary(int data){
        if (this->set_made == false)
        {
            vector<int> check;
            this->arr = check;
            this->arr.push_back(data);
            this->set_made = true;
        }
        else
        {
            if (this->arr.size() == 0)
            {
                this->arr.push_back(data);
            }
            else
            {   
                int lower=0;
                int upper = this->arr.size()-1;
                int mid=(lower+upper)/2;
                while (lower<=upper){
                    if (this->arr[lower]>data){
                        mid=lower;
                        this->arr.insert(this->arr.begin() + mid, data);
                        break;
                    }
                    if (this->arr[upper]<data){
                        mid=upper+1;
                        this->arr.insert(this->arr.begin() + mid, data);
                        break;
                    }
                    if (this->arr[mid]<data){
                        lower=mid+1;
                        mid=(lower+upper)/2;
                    }
                    else if (this->arr[mid]==data){
                        break;
                    }
                    else{
                        upper=mid-1;
                        mid=(lower+upper)/2;
                    }
                }         
                } 
            }
            return this->arr.size(); 
    }

    int insertion(int data)
    {
        if (this->set_made == false)
        {
            // cout<<"jhd"<<endl;
            vector<int> check;
            this->arr = check;
            this->arr.push_back(data);
            this->set_made = true;
        }
        else
        {
            if (this->arr.size() == 0)
            {
                this->arr.push_back(data);
            }
            else
            {
                int j = 0;
                while (j < this->arr.size())
                {
                    if (this->arr[j] < data)
                    {
                        j += 1;
                    }
                    else if (this->arr[j] != data)
                    {
                        this->arr.insert(this->arr.begin() + j, data);
                        break;
                    }
                    else if (this->arr[j] > data)
                    {
                        this->arr.insert(this->arr.begin(), data);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                if (j == this->arr.size() and this->arr[j] != data)
                {
                    this->arr.push_back(data);
                }
                // return ar.size();
            }
        }
        return this->arr.size();
    }

    int deletionbinary(int data)
    {
        if (this->set_made == false)
        {
            return -1;
        }
        else
        {
            int lower = 0;
            int upper = this->arr.size() - 1;
            bool found = false;
            int mid = 0;
            while (lower <= upper)
            {
                mid = ((lower + upper) / 2);
                if (this->arr[lower] > data)
                {
                    break;
                }
                if (this->arr[upper] < data)
                {
                    break;
                }
                if (this->arr[mid] < data)
                {
                    lower = mid + 1;
                }
                else if (this->arr[mid] == data)
                {
                    found = true;
                    break;
                }
                else
                {
                    upper = mid - 1;
                }
            }
            if (found)
            {
                this->arr.erase(this->arr.begin() + mid);
                return this->arr.size();
            }
            else
            {
                return this->arr.size() ;
            }
        }
    }

    int deletion(int data)
    {
        if (this->set_made == false)
        {
            return -1;
        }
        else
        {
            int j = 0;
            while (j < this->arr.size())
            {
                if (this->arr[j] != data)
                {
                    j += 1;
                }
                else
                {
                    break;
                }
            }
            if (j != this->arr.size())
            {
                this->arr.erase(this->arr.begin() + j);
            }
            return this->arr.size();
        }
    }

    int belongstobinary(int data)
    {
        if (this->set_made == false)
        {
            // cout<<"dsh"<<endl;
            return -1;
        }
        else
        {
            int lower = 0;
            int upper = this->arr.size() - 1;
            bool found = false;
            while (lower <= upper)
            {
                int mid = ((lower + upper) / 2);
                if (this->arr[lower] > data)
                {
                    break;
                }
                if (this->arr[upper] < data)
                {
                    break;
                }
                if (this->arr[mid] < data)
                {
                    lower = mid + 1;
                }
                else if (this->arr[mid] == data)
                {
                    found = true;
                    break;
                }
                else
                {
                    upper = mid - 1;
                }
            }
            return found;
        }
    }

    int belongsto(int data)
    {
        if (this->set_made == false)
        {
            return -1;
        }
        else
        {
            int j = 0;
            while (j < this->arr.size())
            {
                if (this->arr[j] != data)
                {
                    j += 1;
                }
                else
                {
                    break;
                }
            }
            if (j == this->arr.size())
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }

    int unionnn(vector<int> arw)
    {
        int i = 0;
        int j = 0;
        if (this->set_made == false)
        {
            vector<int> check;
            this->arr = check;
            this->set_made = true;
        }
        vector<int> neq;
        while (i < this->arr.size() && j < arw.size())
        {
            if (this->arr[i] > arw[j])
            {
                neq.push_back(arw[j]);
                j += 1;
            }
            else if (this->arr[i] == arw[j])
            {
                neq.push_back(this->arr[i]);
                i += 1;
                j += 1;
            }
            else
            {
                neq.push_back(this->arr[i]);
                i += 1;
            }
        }
        while (i < this->arr.size())
        {
            neq.push_back(this->arr[i]);
            i += 1;
        }
        while (j < arw.size())
        {
            neq.push_back(arw[j]);
            j += 1;
        }
        this->arr = neq;
        return this->arr.size();
    }

    int unionn(vector<int> arw)
    {
        if (this->set_made = false)
        {
            vector<int> check;
            this->arr = check;
            this->set_made = true;
        }
        for (int i = 0; i < arw.size(); i++)
        {
            this->insertion(arw[i]);
        }
        return this->arr.size();
    }

    int intersection(vector<int> arw)
    {
        int i = 0;
        int j = 0;
        if (this->set_made == false)
        {

            vector<int> check;
            this->arr = check;
            this->set_made = true;
        }
        vector<int> neq;
        while (i < this->arr.size() && j < arw.size())
        {
            if (this->arr[i] > arw[j])
            {
                j += 1;
            }
            else if (this->arr[i] == arw[j])
            {
                neq.push_back(this->arr[i]);
                i += 1;
                j += 1;
            }
            else
            {
                i += 1;
            }
        }
        this->arr = neq;
        return this->arr.size();
    }

    int sizee()
    {
        if (this->set_made == false)
        {
            vector<int> check;
            this->arr = check;
            this->set_made = true;
        }
        return this->arr.size();
    }

    void print()
    {
        for (int i = 0; i < this->arr.size(); i++)
        {
            if (i == this->arr.size() - 1)
            {
                cout << this->arr[i];
            }
            else
            {
                cout << this->arr[i] << ",";
            }
        }
        cout << endl;
    }

    int difference(vector<int> arw)
    {
        int i = 0;
        int j = 0;
        if (this->set_made == false)
        {
            vector<int> check;
            this->arr = check;
            this->set_made = true;
        }
        vector<int> neq;
        while (i < this->arr.size() && j < arw.size())
        {
            if (this->arr[i] > arw[j])
            {
                // neq.push_back(this->arr[i]);
                j += 1;
            }
            else if (this->arr[i] == arw[j])
            {
                i += 1;
                j += 1;
            }
            else
            {
                neq.push_back(this->arr[i]);
                i += 1;
            }
        }
        while (i < this->arr.size())
        {
            neq.push_back(this->arr[i]);
            i += 1;
        }
        this->arr = neq;
        return this->arr.size();
    }

    int symmetricdifference(vector<int> arw)
    {
        int i = 0;
        int j = 0;
        if (this->set_made == false)
        {
            vector<int> check;
            this->arr = check;
            this->set_made = true;
        }

        vector<int> neq;
        while (i < this->arr.size() && j < arw.size())
        {
            if (this->arr[i] > arw[j])
            {
                neq.push_back(arw[j]);
                j += 1;
            }
            else if (this->arr[i] == arw[j])
            {
                i += 1;
                j += 1;
            }
            else
            {
                neq.push_back(this->arr[i]);
                i += 1;
            }
        }
        while (i < this->arr.size())
        {
            neq.push_back(this->arr[i]);
            i += 1;
        }
        while (j < arw.size())
        {
            neq.push_back(arw[j]);
            j += 1;
        }
        this->arr = neq;
        return this->arr.size();
    }
};

int main()
{   
    // #ifndef ONLINE_JUDGE
    //     // freopen("input.txt","r",stdin);
    //     freopen("outputt.txt","w",stdout);
    // #endif
    SET ar[100011];
    int oper;
    while (cin>>oper)
    {    
        int set_num;   
        cin >> set_num;
        if (oper != 6 && oper != 9)
        {
            int data;
            cin >> data;
            if (oper == 1)
            {
                int p = ar[set_num].insertionbinary(data);
                cout << p << endl;
            }
            else if (oper == 2)
            {
                int p = ar[set_num].deletionbinary(data);
                cout << p << endl;
            }
            else if (oper == 3)
            {
                int p = ar[set_num].belongstobinary(data);
                cout << p << endl;
            }
            else if (oper == 4)
            {
                if (ar[data].arr.size() == 0)
                {
                    vector<int> check;
                    ar[data].arr = check;
                    ar[data].set_made = true;
                }
                int p = ar[set_num].unionnn(ar[data].arr);
                cout << p << endl;
            }
            else if (oper == 5)
            {
                if (ar[data].arr.size() == 0)
                {
                    vector<int> check;
                    ar[data].arr = check;
                    ar[data].set_made = true;
                }
                int p = ar[set_num].intersection(ar[data].arr);
                cout << p << endl;
            }
            else if (oper == 7)
            {
                if (ar[data].arr.size() == 0)
                {
                    vector<int> check;
                    ar[data].arr = check;
                    ar[data].set_made = true;
                }
                int p = ar[set_num].difference(ar[data].arr);
                cout << p << endl;
            }
            else if (oper == 8)
            {
                if (ar[data].arr.size() == 0)
                {
                    vector<int> check;
                    ar[data].arr = check;
                    ar[data].set_made = true;
                }
                int p = ar[set_num].symmetricdifference(ar[data].arr);
                cout << p << endl;
            }
        }
        else if (oper == 6)
        {
            int p = ar[set_num].sizee();
            cout << p << endl;
        }
        else if (oper == 9)
        {
            ar[set_num].print();
        }
        // testcase--;
    }
    return 0;
}