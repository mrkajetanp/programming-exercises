import matplotlib.pyplot as plt
from IPython import display
import numpy as np

import skimage.io, skimage.color

def load_image_colour(fname):
    img = skimage.io.imread(fname)
    return img.astype(np.float64)/255.0

def load_image_gray(fname):
    img = skimage.color.rgb2gray(skimage.io.imread(fname))
    return img.astype(np.float64)

def show_frames(img_seq, n=10):
    plt.figure(figsize=(16,4))
    for i in range(n):        
        plt.subplot(1,n, i+1)
        ix = int((i*img_seq.shape[0]) / float(n))
        show_image(img_seq[ix])
    
def show_image(array):    
    plt.figure()
    if len(array.shape)==2 or array.shape[2]==1:
        array = array.reshape(array.shape[0], array.shape[1])
        array = np.clip(array,0,1)        
        plt.imshow(array, interpolation="nearest", cmap="gray",vmin=0,vmax=1)
    
    if len(array.shape)==3:        
        array = np.clip(array[:,:,0:3],0,1)
        plt.imshow(array, interpolation="nearest")        
    plt.axis("off")
import time

def update_image(array):
    

    if len(array.shape)==2 or array.shape[2]==1:
        array = array.reshape(array.shape[0], array.shape[1])
        array = np.clip(array,0,1)        
        plt.imshow(array, interpolation="nearest", cmap="gray",vmin=0,vmax=1)
    
    if len(array.shape)==3:        
        array = np.clip(array[:,:,0:3],0,1)
        plt.imshow(array, interpolation="nearest")        
    plt.axis("off")
    
    display.display(plt.gcf())
    display.clear_output(wait=True)
    time.sleep(0.1)

    
import scipy.io.wavfile
import IPython
def load_sound(wav_file):    
    sr, sound = scipy.io.wavfile.read(wav_file)
    sound = sound.astype(np.float64)/32767.0
    if len(sound.shape)>1:
        sound = (sound[:,0]/2 + sound[:,1]/2)
    return sound

def play_sound(audio,sr=44100):
    audio = (np.clip(audio,-1,1)*32767.0).astype(np.int16)
    audio[-1] = -32767
    audio[-2] = 32767    
    sp = IPython.display.Audio(audio, rate=sr)
    return sp

def plot_sound(audio):
    ts = np.arange(len(audio))/44100.0
    plt.plot(ts, audio, 'c', alpha=0.5)
    plt.xlabel("Time (s)")    