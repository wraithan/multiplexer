# Multiplexer

This uses arduino libraries to talk to [CD74HC4067](http://www.ti.com/lit/ds/symlink/cd74hc4067.pdf) which is a 16 channel multiplexer.

## Usage

```C++
Multiplexer multi (15, 16, 17, 18, 14);
multi.write(5, HIGH);
```

## Args

The constructor takes the number of 5 pins, the first for are S0-S3 on the multiplexer, the last is the data pin which is used for reading/writing.

## Future

* Make this a [dotc](https://github.com/substack/dotc) module.
* Add a read() fuction since most people are probably reading not writing with their multiplexers.