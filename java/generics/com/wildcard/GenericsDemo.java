package com.wildcard;

class Info<T> {
	private T mVar;
	public void setVar(T var) {
		this.mVar = var;
	}

	public T getVar() {
		return this.mVar;
	}

	public String toString() {
		return this.mVar.toString();
	}
}

public class GenericsDemo {
	public static void main(String[] args) {
		Info<String> i = new Info<String>();
		i.setVar("it");
		fun(i);
	}
	
	public static void fun(Info<?> temp) {
		System.out.println("content: "+temp);
	}
}
