using UnityEngine;
using System.Collections;

public class globalController : MonoBehaviour {

    [SerializeField]
    private cameraController camControl;
    [SerializeField]
    private accelerometerControl acc;
    [SerializeField]
    private gyroscopeControl gyr;
    [SerializeField]
    private potardController pot;

    // Use this for initialization
    void Start () {
	
	}

    public void cameraControlSetVignette(float input)
    {
        camControl.setVignetteValue(input);
    }
	
    public void potardSetAngle(float angle)
    {
        pot.setAngle(angle);
    }

    public void AccSetAcc(float x, float y, float z)
    {
        acc.setAcc(x, y, z);
    }

    public void GyrSetGyr(float x, float y, float z)
    {
        gyr.setGyr(x, y, z);
    }

    // Update is called once per frame
    void Update () {
	
	}
}
