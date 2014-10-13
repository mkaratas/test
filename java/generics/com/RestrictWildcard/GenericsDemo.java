package com.RestrictWildcard;

class Info<T> {
	private T mVar;
	
	public void setVar(T var) {
		this.mVar = var;
	}

	public T getVar() {
		return this.mVar;
	}

	public String toString() {
		//return this.mVar.toString();
		return null;
	}
};

public class GenericsDemo {
	public static void main(String[] args) {
		Info<Integer> i1 = new Info<Integer>();
		Info<Float> i2 = new Info<Float>();
		i1.setVar(10);		
		i2.setVar(10.111f);		
		fun(i1);
		fun(i2);
	}

	public static void fun(Info<? extends Number> temp) {
		System.out.println(temp + "/");
	}
};
