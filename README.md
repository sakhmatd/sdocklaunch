# sdocklaunch

A simple dock-style program launcher.

Intended to be used on machines with touch-screens and brought up via a keyboard shortcut or a gesture,
but certainly works in other environments.

## Prerequisites

* GCC (Clang also works)
* GTK2

## Installing

Build the binary with:

```
make
```

Install the binary with:

```
sudo make install
```

## Configuration

Please see ```config.h``` and set variables according to your liking
before using sdocklaunch.

Note that you will have to run the procedure listed above to reinstall
sdocklaunch after you make any changes to the configuration. 

## Contributing

Contributions are welcome no matter who you are and where you come from.

When submitting PRs, please try to maintain the [coding style](https://suckless.org/coding_style/)
used for the project.

## License

Copyright 2019 Sergei Akhmatdinov

Licensed under the Apache License, Version 2.0 (the "License");
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
