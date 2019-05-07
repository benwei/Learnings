import org.juluos.sample.HelloJNI;
public class mytest{
    public static void main(String[] args) {
        HelloJNI hjni = new HelloJNI();
        int a = hjni.add(10, 11);
        System.out.println("add result: " + a);
    }
}
