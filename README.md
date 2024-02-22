## Test Task: Improve/refactor Image cache class
The current project uses a 3rd party library for image handling. The library provides an **Image** class and two functions, **LoadImage** and **ReleaseImage**, for loading and releasing images from memory. As the same images can be loaded several times, it was decided to implement a small class, **ImageCache**, to keep already loaded images in memory. The task was assigned to a "junior" developer who didn't implement it in the best way.

Your task is to refactor this **ImageCache** class to improve its security, maintainability, and possibly performance. The class should work safely in a multithreading environment.

Feel free to change everything in this class, including the interface, naming, approaches, etc.

Remember to follow good coding practices and principles. Good luck!
