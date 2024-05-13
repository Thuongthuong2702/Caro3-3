using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameOverScript : MonoBehaviour
{
    public Button restartButton;
     private void Awake(){
        restartButton.onClick.AddListener(OnClick);
    }
   public void OnClick(){
    SceneManager.LoadScene("MainScreen");

   }
}
