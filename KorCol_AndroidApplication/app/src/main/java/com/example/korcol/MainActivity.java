package com.example.korcol;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import android.widget.Button;
import android.widget.TextView;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.net.UnknownHostException;

public class MainActivity extends AppCompatActivity {

    TextView buttonClickTextView;
    Button bLED1;
    Button bLED2;
    Button bLED3;
    Button bLED4;
    Button bMotor1;
    Button bMotor2;
    Button bMotor3;
    Button bHumidity;

    //String Msg;
    Socket socket;
    String ip = "192.168.43.212";
    int port = 4000;

    String Tag = "my";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        //r.di.string 이렇게 해서 가져오기
        buttonClickTextView = findViewById(R.id.button_click_text_view);
        bLED1 = (Button)findViewById(R.id.buttonLED1);
        bLED2 = (Button)findViewById(R.id.buttonLED2);
        bLED3 = (Button)findViewById(R.id.buttonLED3);
        bLED4 = (Button)findViewById(R.id.buttonLED4);
        bMotor1 = (Button)findViewById(R.id.Motor1);
        bMotor2 = (Button)findViewById(R.id.Motor2);
        bMotor3 = (Button)findViewById(R.id.Motor3);
        bHumidity = (Button)findViewById(R.id.Hum);

    }

    class ConnectThread implements Runnable {
        String msg;
        public void run(){
            Log.d(Tag, "Thread start");
            try{
                InetAddress serverAddr = InetAddress.getByName(ip);
                socket = new Socket(serverAddr, port);
                //String sendMsg = Msg;
                PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
                System.out.println("ssss\n");
                out.println(msg);
                socket.close();

            } catch (UnknownHostException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        public void setMsg(String message){
            this.msg = message;
        }

    }

    public void buttonLED1Click(View view) {
        //buttonClickTextView.setText(bLED1.getText());
        if(bLED1.getText().equals("LED1 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on LED 1");
            new Thread(th).start();
            bLED1.setText("LED1 Off");

        }
        else if(bLED1.getText().equals("LED1 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off LED 1");
            new Thread(th).start();
            Log.d(Tag, "Button off touch");
            bLED1.setText("LED1 On");
        }

    }
    public void buttonLED2Click(View view) {
        if(bLED2.getText().equals("LED2 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on LED 2");
            new Thread(th).start();
            bLED2.setText("LED2 Off");
        }
        else if(bLED2.getText().equals("LED2 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off LED 2");
            new Thread(th).start();
            bLED2.setText("LED2 On");
        }
    }

    public void buttonLED3Click(View view) {
        if(bLED3.getText().equals("LED3 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on LED 3");
            new Thread(th).start();
            bLED3.setText("LED3 Off");
        }
        else if(bLED3.getText().equals("LED3 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off LED 3");
            new Thread(th).start();
            bLED3.setText("LED3 On");
        }
    }

    public void buttonLED4Click(View view) {
        if(bLED4.getText().equals("LED4 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on LED 4");
            new Thread(th).start();
            bLED4.setText("LED4 Off");
        }
        else if(bLED4.getText().equals("LED4 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off LED 4");
            new Thread(th).start();
            bLED4.setText("LED4 On");
        }
    }

    public void buttonMotor1Click(View view) {
        if(bMotor1.getText().equals("Motor1 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on Motor 1");
            new Thread(th).start();
            bMotor1.setText("Motor1 Off");
        }
        else if(bMotor1.getText().equals("Motor1 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off Motor 1");
            new Thread(th).start();
            bMotor1.setText("Motor1 On");
        }
    }

    public void buttonMotor2Click(View view) {
        if(bMotor2.getText().equals("Motor2 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on Motor 2");
            new Thread(th).start();
            bMotor2.setText("Motor2 Off");
        }
        else if(bMotor2.getText().equals("Motor2 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off Motor 2");
            new Thread(th).start();
            bMotor2.setText("Motor2 On");
        }
    }

    public void buttonMotor3Click(View view) {
        if(bMotor3.getText().equals("Motor3 On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on Motor 3");
            new Thread(th).start();
            bMotor3.setText("Motor3 Off");
        }
        else if(bMotor3.getText().equals("Motor3 Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off Motor 3");
            new Thread(th).start();
            bMotor3.setText("Motor3 On");
        }
    }

    public void buttonHumClick(View view) {
        if(bHumidity.getText().equals("Humidity On")){
            ConnectThread th = new ConnectThread();
            th.setMsg("on Hum");
            new Thread(th).start();
            bHumidity.setText("Humidity Off");
        }
        else if(bHumidity.getText().equals("Humidity Off")){
            ConnectThread th = new ConnectThread();
            th.setMsg("off Hum");
            new Thread(th).start();
            bHumidity.setText("Humidity On");
        }
    }

}
