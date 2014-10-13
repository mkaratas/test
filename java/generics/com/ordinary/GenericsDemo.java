package com.ordinary;

class Point<T> {
	private T mVar;
	
	public void setVal(T s) {
		this.mVar = s;
	}	

	public T getVal() {
		return mVar;
	}
}

public class GenericsDemo {
	public static void main(String[] args) {
		Point<String> p = new Point<String>();
		p.setVal("it");
		System.out.println("Var = "+p.getVal());
	}
}
