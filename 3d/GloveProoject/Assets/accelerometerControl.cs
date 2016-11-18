using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class accelerometerControl : MonoBehaviour {

    [SerializeField]
    private Text X;
    [SerializeField]
    private Text Y;
    [SerializeField]
    private Text Z;

    private float valueX = 0.0f;
    private float valueY = 0.0f;
    private float valueZ = 0.0f;
    // Use this for initialization
    void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

        X.text = "X : " + valueX.ToString();
        Y.text = "Y : " + valueY.ToString();
        Z.text = "Z : " + valueZ.ToString();

    }

    public void setAcc(float x, float y, float z)
    {
        setValueX(x);
        setValueY(y);
        setValueZ(z);
    }

    public void setValueX(float input)
    {
        valueX = input;
    }

    public void setValueY(float input)
    {
        valueY = input;
    }

    public void setValueZ(float input)
    {
        valueZ = input;
    }
}
