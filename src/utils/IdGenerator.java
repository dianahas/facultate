package utils;

public class IdGenerator {
	private static int counter = 0;
	public static int generator(){
		return ++counter;
	}
}
