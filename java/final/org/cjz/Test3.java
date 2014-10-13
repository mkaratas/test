package org.cjz;

public class Test3 {
	public static final int D = 20;
	public final int E;

	public Test3(int x) {
		E = x;
	}	

	public static void main(String[] args) {
		Test3 t = new Test3(88);
		System.out.println(t.E);
		System.out.println("static final int D = " + t.D);
		System.out.println("static final int D = " + Test3.D);
		
		//System.out.println("E = "+Test3.E);
		System.out.println("E = "+t.E);
	}
}
