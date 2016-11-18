using UnityEngine;
using System.Collections;
using UnityStandardAssets.ImageEffects;

public class cameraController : MonoBehaviour {

    public VignetteAndChromaticAberration vign;

	// Use this for initialization
	void Start () {
        
    }
	
	// Update is called once per frame
	void Update () {
	
	}

    public void setVignetteValue(float input)
    {
        vign.intensity = input;

    }
}
