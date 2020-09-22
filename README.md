# Steganography

Steganography approach in this project will encode secret data within the pixel data of
an otherwise uninteresting image. Humans are not very good at detecting tiny differences in color – for
example, the full red RGB of (255, 0, 0) is essentially not distinguishable from the almost-full red RGB of (254, 1,
1). Therefore, we can make tiny modifications to colors and a human will not be able to detect the differences.

By modifying a portion of an image such that whether the individual RGB components
are even or odd, we can encode 8 informative text codes into 8 different colors, as described here:

* Encoding value: 0, Color description: Black, Encoding RGB: (Even, Even, Even)
* Encoding value: 1, Color description: Red, Encoding RGB: (Odd, Even, Even)
* Encoding value: 2, Color description: Green, Encoding RGB: (Even, Odd, Even)
* Encoding value: 3, Color description: Blue, Encoding RGB: (Even, Even, Odd)
* Encoding value: 4, Color description: White, Encoding RGB: (Odd, Odd, Odd)
* Encoding value: 5, Color description: Yellow, Encoding RGB: (Odd, Odd, Even)
* Encoding value: 6, Color description: Magenta, Encoding RGB: (Odd, Even, Odd)
* Encoding value: 7, Color description: Cyan, Encoding RGB: (Even, Odd, Odd)

Given the text input, the RGB components of a pixel are tweaked by
at most 1, which will be undetectable. Here’s how it will work – let’s say the current pixel value we’re going to
encode is made up of RGB values of (108, 217, 62). If we want to encode the color yellow into the pixel, we
need (Odd, Odd, Even), so we modify the RGB values to be (109, 217, 62). Similarly, if we had wanted to encode
the color green, we need (Even, Odd, Even) – if the original pixel value was (108, 217, 62), then no changes are
needed, as it already represents the encoded color green. As a final example, if we wanted to encode the color
magenta, we need (Odd, Even, Odd), and again starting with (108, 217, 62), we can see that all three color
components need to be modified, resulting in (109, 216, 63).

Algorithmically, here is the description: If a color attribute is even and we need to encode even, or it is odd and
we need to encode odd, then no change to the value is made. If a color is odd and we need to encode even,
then we simply subtract one from its value. Finally, if a color is even, and we need to encode odd, then we add
one to its value. Notice that we don’t need to worry about “special cases” at the boundaries with this algorithm,
because we never subtract from an even number, so we’d never subtract from 0 (which would result in an
invalid -1 color attribute), and we never add to an odd number, so we’d never add to 255 (which would result in
an invalid 256 color attribute).

####An example:

