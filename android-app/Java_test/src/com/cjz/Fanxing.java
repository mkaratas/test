package com.cjz;

import java.util.Vector;

class Generic<T> {
	private T f;
	public void setF(T f) {
		this.f = f;
	}
	public T getF() {
		return f;
	}
}

public class Fanxing {
	public static void main(String args[]) {
		Vector<String> v = new Vector<String>();
		v.add("hello");
		String name = v.get(0);

		System.out.println("name = " + name);

		Generic<Boolean> f1 = new Generic<Boolean>();
	}
}
