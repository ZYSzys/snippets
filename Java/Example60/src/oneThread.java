public class oneThread extends Thread {
    public oneThread() {

    }

    public void run() {
        System.out.println("...........oneThread begining..........");
        int flag = 1;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < flag; j++)
                System.out.print("*");
            System.out.println("");
            flag++;
            try {
                sleep(100);
            }catch (Exception e) {
                System.out.println(e);
            }
            if(i == 9)
                System.out.println("............oneThread ending...........");
        }
    }

    public static void main(String[] args) {
        new oneThread().start();
    }
}
