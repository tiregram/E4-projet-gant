/* ArduinoConnector by Alan Zucconi
 * http://www.alanzucconi.com/?p=2979
 */
using UnityEngine;
using System;
using System.Collections;
using System.IO.Ports;

public class networkController : MonoBehaviour
{

    public globalController glob;
   


    void Start()
    {
        Open();
        StartCoroutine("appel");
    }

    // Update is called once per frame
    void Update()
    {

        if(Time.time > 0.5f && Time.time % 1 <= 0.5)
        {
            //WriteToArduino("POTARD");
            
                //StartCoroutine("appel");



            //Debug.Log(a);
        }

           
        

        //glob.potardSetAngle(float.Parse(a));




    }


    /* The serial port where the Arduino is connected. */
    [Tooltip("The serial port where the Arduino is connected")]
    public string port = "COM4";
    /* The baudrate of the serial port. */
    [Tooltip("The baudrate of the serial port")]
    public int baudrate = 9600;

    private SerialPort stream;

    public IEnumerator appel()
    {

        while(true)
        {
            WriteToArduino("POTARD");
            yield return new WaitForSeconds(0.05f);
            Debug.Log("Bonjour, je suis lilan Buzer et je viens hanter ce port serie");
            string a = ReadFromArduino(2000);


            if (a != null)
            {
                Debug.Log(a);
                float temp = float.Parse(a);
                //debug sur GUI
                glob.potardSetAngle(18 * temp);

                //action reele
                if(temp >= 0 && temp <= 20)
                    glob.cameraControlSetVignette(0.05f * temp);
            }
            yield return new WaitForSeconds(0.01f);

        }



        //float Ax = 0.0f;
        //float Ay = 0.0f;
        //float Az = 0.0f;

            //float Gx = 0.0f;
            //float Gy = 0.0f;
            //float Gz = 0.0f;



            //if (a != null)
            //{
            //    Debug.Log(a);
            //    String[] substrings = a.Split(',');
            //    Ax = float.Parse(substrings[0]);
            //    Ay = float.Parse(substrings[1]);
            //    Az = float.Parse(substrings[2]);

            //    Gx = float.Parse(substrings[3]);
            //    Gy = float.Parse(substrings[4]);
            //    Gz = float.Parse(substrings[5]);

            //    glob.AccSetAcc(Ax, Ay, Az);
            //    glob.GyrSetGyr(Gx, Gy, Gz);
            //}

            //yield return new WaitForSeconds(0.5f);

    }

    public void Open()
    {
        // Opens the serial port
        stream = new SerialPort(port, baudrate);
        stream.ReadTimeout = 50;
        stream.Open();
        //this.stream.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
        Debug.Log("Init Done !");
    }

    public void WriteToArduino(string message)
    {
        // Send the request
        stream.WriteLine(message);
        stream.BaseStream.Flush();
    }

    public string ReadFromArduino(int timeout = 0)
    {
        stream.ReadTimeout = timeout;
        try
        {
           
            return stream.ReadLine();
            Debug.Log("pop");
        }
        catch (TimeoutException)
        {
            Debug.Log("timeoutExp");
            return null;
        }
    }


    public IEnumerator AsynchronousReadFromArduino(Action<string> callback, Action fail = null, float timeout = float.PositiveInfinity)
    {
        DateTime initialTime = DateTime.Now;
        DateTime nowTime;
        TimeSpan diff = default(TimeSpan);

        string dataString = null;

        do
        {
            // A single read attempt
            try
            {
                dataString = stream.ReadLine();
            }
            catch (TimeoutException)
            {
                dataString = null;
            }

            if (dataString != null)
            {
                callback(dataString);
                yield return null;
            }
            else
                yield return new WaitForSeconds(0.05f);

            nowTime = DateTime.Now;
            diff = nowTime - initialTime;

        } while (diff.Milliseconds < timeout);

        if (fail != null)
            fail();
        yield return null;
   }

    public void Close()
    {
        stream.Close();
    }
}