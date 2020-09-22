# Steganography

Steganography approach in this project will encode secret data within the pixel data of
an otherwise uninteresting image. Humans are not very good at detecting tiny differences in color – for
example, the full red RGB of (255, 0, 0) is essentially not distinguishable from the almost-full red RGB of (254, 1,
1). Therefore, we can make tiny modifications to colors and a human will not be able to detect the differences.

By modifying a portion of an image such that whether the individual RGB components
are even or odd, we can encode 8 different colors, as described here:

* Encoding value: 0, Color description: Black, Encoding RGB: (Even, Even, Even)
* Encoding value: 1, Color description: Red, Encoding RGB: (Odd, Even, Even)
* Encoding value: 2, Color description: Green, Encoding RGB: (Even, Odd, Even)
* Encoding value: 3, Color description: Blue, Encoding RGB: (Even, Even, Odd)
* Encoding value: 4, Color description: White, Encoding RGB: (Odd, Odd, Odd)
* Encoding value: 5, Color description: Yellow, Encoding RGB: (Odd, Odd, Even)
* Encoding value: 6, Color description: Magenta, Encoding RGB: (Odd, Even, Odd)
* Encoding value: 7, Color description: Cyan, Encoding RGB: (Even, Odd, Odd)
