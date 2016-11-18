using UnityEngine;
using System.Collections;

public class potardController : MonoBehaviour {
    [SerializeField]
    public RectTransform Arrow;


	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

        //if (Input.GetKeyDown(KeyCode.Space))
        //    setAngle(Time.time);
	}

    public void setAngle(float input)
    {
        Arrow.transform.rotation = Quaternion.Euler(0, 0, input);
    }
}
