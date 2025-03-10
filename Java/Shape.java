//Write java program to create a super class called "shape" that receives the domensions of object
import java.lang.*;
import java.util.*;
class Shape1{
	int l=10,w=5;
	Shape1(int a,int b){
		
		System.out.println("constructor of super class Shape1:"+ a + " "+ b);
	}
	
	 void area(int i,int w){
	 	System.out.println("Area of rectangle using Super method:" + l*w);
	 }
}
class rectangle extends Shape1{
	rectangle(int a,int b){
		super(10, 80); // Call the constructor of Shape1 with two arguments
		System.out.println("Constructor of sub class: "+a + " "+ b);
	}
	void area(int l , int w){
		//Super method in sub class
		super.area(10,8);
	
		System.out.println("Area of rectangle:" + l*w);
		
		//Super keyword for variable
		System.out.println("Area of rectangle using super keyword:" + super.l * super.w);
	}
	
}

class triangle extends Shape1{
	triangle(int a, int b) {
        	super(a, b);  // Call the constructor of Shape1 with two arguments
    	}
    	
	void area(float b,float h){
		System.out.println("Area of triangle:"+ 0.5 * b * h);
	}
}

class shape{
	public static void main(String args[]){
	rectangle r=new rectangle(10,5);
	r.area(10,6);	
	
	triangle t=new triangle(10,2);
	t.area(10,5);
	}
}
