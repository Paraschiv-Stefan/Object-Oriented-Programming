#include<iostream>
using namespace std;
class tree{
	private:
		int height;
	public:
		tree():height(0){}
		tree(int c):height(c){}
		tree(const tree& c):height(c.height){}
		~tree(){ cout<<"Destructor initialized";}
		void printheight()
		{
			cout<<"the length of the tree is: ";
			cout<<height<<endl;
		}
		tree operator>(tree& f);
		void grow(int gr)
		{
			height=height+gr;
		}
		tree& operator++() 
		{
           height++;
           return *this;
           //postfixed
        }
    	tree operator++(int) 
		{
        	tree copy = *this;
            ++height;
            return copy;
            //prefixed
    	}
    	
};
int main()
{
	tree t1;
	t1.printheight();
	tree t2(30);
	t2.printheight();
	t1=t2;
	t1.printheight();
	++t1;
	t1.printheight();
	t1++;
	t1.printheight();
	
	return 0;
}
