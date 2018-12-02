public class threadCtrl {
    public static void main(String[] args) {
        new threadCtrl();
    }

    threadCtrl() {
        try {
            Thread tm = Thread.currentThread();
            threadchild td = new threadchild();
            td.start();
            tm.sleep(1000);
            System.out.println("interrupt child thread");
            td.interrupt();

            System.out.println("let child thread wait!");
            tm.sleep(4000);

            System.out.println("let child thread working");
            td.fauxresume();
            tm.sleep(1000);
            td.runflag = false;
            tm.sleep(1000);
            System.out.println("main over......");
        }catch (InterruptedException ie) {
            System.out.println("inter main: " + ie);
        }catch (Exception e) {
            System.out.println("main: " + e);
        }
    }
}

class threadchild extends Thread {
    boolean runflag = true;
    boolean suspended = true;

    threadchild() {}

    public synchronized  void fauxresume() {
        suspended = false;
        notify();
    }

    public void run() {
        while(runflag) {
            System.out.println("I am working......");
            try {
                sleep(200);
            }catch (InterruptedException e) {
                System.out.println("sleep: " + e);
            }

            synchronized (this) {
                try {
                    if(suspended)
                        wait();
                }catch (InterruptedException e) {
                    System.out.println("wait: " + e);
                }
            }
        }
        System.out.println("thread over.......");
    }
}