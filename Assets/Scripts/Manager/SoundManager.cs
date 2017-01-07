using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : SingletonMonoBehaviour<SoundManager> {

    [SerializeField]
    private AudioSource seSource;
    [SerializeField]
    private AudioSource bgmSource;

    protected override void Awake(){
        base.Awake();
        DontDestroyOnLoad(this.gameObject);
    }

    /// <summary>
    /// システム音を鳴らす関数
    /// </summary>
    /// <param name="clip">鳴らしたいAudioClip</param>
    public void SoundSe(AudioClip clip)
    {
        seSource.clip = clip;
        seSource.Play();
    }

    /// <summary>
    /// BGMを鳴らす関数
    /// </summary>
    /// <param name="clip">鳴らしたいBGM</param>
    public void SoundBGM(AudioClip clip)
    {
        bgmSource.clip = clip;
        bgmSource.Play();
    }

    /// <summary>
    /// BGMの停止
    /// </summary>
    public void StopBGM()
    {
        bgmSource.Stop();
    }

}
