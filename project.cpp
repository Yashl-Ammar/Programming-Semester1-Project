#include <iostream>
#include <thread> // used for delay

using namespace std;

void firework(char grid[30][50]); // prototype for the firework

int main()
{
	
	const int x = 30;
	const int y = 50;
	char grid[x][y]; // our grid we will manipulate 
	for (int i = 0 ; i < x ; i++) // assigning the grid to empty space
	{
		for (int j = 0 ; j < y ; j++)
		{
			grid[i][j] = ' ' ;
		}
	}
	firework(grid); // calling function for the firework
}


void firework(char grid[30][50])
{
	
	// declaration
	const int x = 30; // we are declaring this again so we can use it in this function too
	const int y = 50; // we are declaring this again so we can use it in this function too
	int grad = 15;    // this will be used for changing the gradient(Curvature)
	int ph ;	   // this will be used for changing the gradient(Curvature)
	int firework_launch = 29; // the firwork will launch from the bottom this indicates the starting point in the grid
	
	
	
	for (int k = 1 ; k <= 14 ; k++) // this is the total number of loops that will happen to show the animation of the firework
	{
		for (int i = 0 ; i < x ; i++) // this reassigns the grid to be empty so we can then change the char in grid to make the next frame
		{
			for (int j = 0 ; j < y ; j++)
			{
				grid[i][j] = ' ' ; // assigning the grid to space so we can use that empty space later to make the firework
			}
		}
		grid[firework_launch][27] = '|'; // the starting point of the 
		firework_launch--;		  // this will make the firework go from bottom to up
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // this is just for asthetic purposes
		
		for (int i = 0 ; i < x ; i++) // this is used to print the grid
		{
			for (int j = 0 ; j < y ; j++)
			{
				cout << grid[i][j] ; // printing
			}
			cout << "\n";
		}
		this_thread::sleep_for(0.075s); // this is used for delay
		if(k == 14) // this is the code for the spiral
		{
			cout << "\a"; // makes the sound of the firework
			/* The first curve(innermost curve). The spiral is made from joining different curves */
			grad = 15;    // this indicates the starting point 
			for (int j = 22; j < 28 ; j++)
			{
				if (j == 22) // this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for ascending) 
					ph = 2;
				else if (j < 27) // this will print 1 * as the loops will loop 1 times so it makes the curve slightly less steep(used for both)
					ph = 1;
				else if (j == 27) // this will print 2 * as the loops will loop 2 times so it makes it more steep again(for decending)
					ph =2;
				for (int i = 0 ; i < ph ;i++ ) // this loop assigns the grid *s such that it will make a curve
				{
					grid[grad][j] = '*'; // assigning *s
					if(j < 24)
						grad--;  // this will go one point up so that it changes the y-axis of the grid so we can kind of make a parabola
					else if (j < 26) // in these parts of the curve we dont want our y-axis to change so that the slope becomes 0 and flat
					{
						// do nothing 
						if(j == 25) // this brings y-axis 1 down so we start the decending part of the curve
							grad++;
					} 
					else if (j >= 26) // this is to make the curve decend 
					{
						grad++;
					}
					
					
					
				}
			}
			/* The second curve(second innermost curve). The spiral is made from joining different curves */
			grad = 15; // this indicates the starting point
			for (int j = 22; j < 35 ; j++) // this curve will start from the same position but will go decend first then ascend and this curve will end abit further out to give it a spiral shape
			{
				if (j < 23) // this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for decnding) 
					ph = 2;
				else if (j < 34) // this will print 1 * as the loops will loop 1 times so it makes the curve slightly less steep(used for both)
					ph = 1;
				else if (j == 34) // this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for ascending) 
					ph = 2;
				for (int i = 0 ; i < ph ; i++)// this loop assigns the grid *s such that it will make a curve
				{
					
					if (j < 25)// this will go one point down so that it changes the y-axis of the grid so we can kind of make a parabola
						grad++;
					else if (j < 27)
					{
						if (j%2 ==0) // by using this we change y-axis for every other loop so it makes the curve have a low steep
						{
							grad++;
						}
					}	
					else if (j < 30)
					{
						// do nothing
					}
					else if (j < 32)
					{
						if (j%2 == 0)// by using this we change y-axis for every other loop so it makes the curve have a low steep
							grad--;
					}
					else if (j >= 32)// in these parts of the curve we dont want our y-axis to change so that the slope becomes 0 and flat
					{
						grad--;
					}
					grid[grad][j] = '*';// assigning *s
					// We are printing this like this to make it seem like an animation we did not do this in the above one because the above curve would print from outward to inward ruining the spiral effect
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					for (int i = 0 ; i < x ; i++)
					{
						for (int j = 0 ; j < y ; j++)
						{
							cout << grid[i][j] ;
						}
						cout << "\n";
						cout << "\a";
					}
					this_thread::sleep_for(0.01s); // for a small delay to make it look like an animation
				}		
			}
			/* The third curve(third innermost curve). The spiral is made from joining different curves */
			grad = 15;// this indicates the starting point
			for (int j = 15; j < 35 ; j++) // the starting point of our curve changes so that the curve gives a spiral effect 
			{
				if (j < 17) // this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for ascending) 
					ph = 2;
				else if (j < 33)	// this will print 1 * as the loops will loop 1 times so it makes the curve slightly less steep(used for both)
			
					ph = 1;
				else if (j >= 33)// this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for decnding) 
					ph =2;
				for (int i = 0 ; i < ph ; i++)// this loop assigns the grid *s such that it will make a curve
				{
					grid[grad][j] = '*';
					if(j < 19)// this will go one point up so that it changes the y-axis of the grid so we can kind of make a parabola
						grad--;
					else if (j < 23)
					{
						if (j%2 == 0)// by using this we change y-axis for every other loop so it makes the curve have a low steep
							grad--;
					}
					else if (j < 27)
					{
						
						// do nothing 
					}
					
					else if (j < 31)
					{
						
						if (j %2 == 1)// by using this we change y-axis for every other loop so it makes the curve have a low steep
							grad++;
					}
					else if(j  >= 31)// this will go one point down so that it changes the y-axis of the grid so we can kind of make a parabola
						grad++;
					
						
					
				}
			}
			/* The fourth curve(second outermost curve). The spiral is made from joining different curves */
			grad = 15;// this indicates the starting point
			for (int j = 14; j < 40 ; j++)// the ending point of our curve changes so that the curve gives a spiral effect 
			{
				if(j < 16)// this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for decnding) 
					ph = 2;
				else if ( j < 34)// this will print 1 * as the loops will loop 1 times so it makes the curve slightly less steep(used for both)
					ph = 1;
				else if (j >= 37)// this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for acending) 
					ph = 2;
				else if ( j >= 34)// this will print 1 * as the loops will loop 1 times so it makes the curve slightly less steep(used for both)
					ph = 1;
				
				for (int i = 0 ; i < ph ; i++)// this loop assigns the grid *s such that it will make a curve
				{
					if(j < 19)// this will go one point down so that it changes the y-axis of the grid so we can kind of make a parabola
						grad++;
					else if(j < 25)// by using this we change y-axis for every other loop so it makes the curve have a low steep
					{
						if (j%2 == 0)
							grad++;	
					}
					else if (j < 28)
					{
					// does nothing
					}
					else if (j < 34)// by using this we change y-axis for every other loop so it makes the curve have a low steep
					{
						if (j%2 == 0)
							grad--;
					}
					else if (j >= 34)// this will go one point up so that it changes the y-axis of the grid so we can kind of make a parabola
						grad--;
					
					grid[grad][j]= '*';
					
					// We are printing this like this to make it seem like an animation we did not do this in the above one because the above curve would print from outward to inward ruining the spiral effect
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					for (int i = 0 ; i < x ; i++)
					{
						for (int j = 0 ; j < y ; j++)
						{
							cout << grid[i][j] ;
						}
						cout << "\n";
						cout << "\a";
					}
					this_thread::sleep_for(0.01s); // for delay
				}
			}
			grad = 15;
			for (int j = 10; j < 40 ; j++)
			{
				if (j < 13)// this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for acending) 
				{
					ph = 2;
				}
				else if( j < 37 ) // this will print 1 * as the loops will loop 1 times so it makes the curve slightly less steep(used for both)
				{
					ph = 1;
				}
				else if (j >= 37)// this will just print 2 straight *s as the loops will loop 2 times so it will make the slope of our curve loop more steep(for decnding) 
				{
					ph = 2;
				}
				for (int i = 0  ; i < ph ; i++)// this loop assigns the grid *s such that it will make a curve
				{
					
					grid[grad][j]= '*'; // assigning *
					if (j < 16)  // this will go one point up so that it changes the y-axis of the grid so we can kind of make a parabola
						grad--;
					else if (j < 22)// by using this we change y-axis for every other loop so it makes the curve have a low steep
					{
						if (j%2 == 0)
							grad--;
					}
					else if (j < 26)
					{
						if (j == 22)
							grad--;
						
						//does nothing
					}
					else if (j < 34)// by using this we change y-axis for every other loop so it makes the curve have a low steep
					{
						
						if (j%2 == 1)
							grad++;
					}
					else if (j >= 34) // this will go one point down so that it changes the y-axis of the grid so we can kind of make a parabola
					{
							grad++;
					}
					
					
					
				}	
			}
			//prints the grid one last time
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			for (int i = 0 ; i < x ; i++)
			{
				for (int j = 0 ; j < y ; j++)
				{
					cout << grid[i][j] ;
				}
				cout << "\n";
				cout << "\a";
			}	
				
		}
		
	}
}
