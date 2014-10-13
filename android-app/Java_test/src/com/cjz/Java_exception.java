package com.cjz;

public class Java_exception {
	String name;

	String get_name() {
		return name;
	}

	public static void main(String args[]) {
		Java_exception ex = new Java_exception();
		ex.get_name().length();
	}
}
