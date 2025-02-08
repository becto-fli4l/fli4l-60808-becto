## fli4l-60808-becto: Time Capsule for fli4l-4 source skeleton with patches ##

Environment: → fbr 2018.02.8 | kernel 5.4.213 / r60808 + patches

source reference:
- https://github.com/becto-fli4l/fli4l-60808-orig
- https://github.com/becto-fli4l/fli4l-prototype

patches:
- patch base -> add igc kernel module: https://github.com/becto-fli4l/fli4l-60808-becto/pull/1
- add OPT umts, add watchdog support, fix latex typo: https://github.com/becto-fli4l/fli4l-60808-becto/pull/2
- patch fli4l-4 skeleton: https://github.com/becto-fli4l/fli4l-60808-becto/pull/3

fli4l can only be compiled with current Linux versions by making several adjustments in buildroot itself, this archive provides the last version for fli4l-r60808 and buildroot 2018.02.8

see → https://hub.docker.com/u/nettworksevtooling for docker images to create a development environment

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see → https://www.gnu.org/licenses/.

If you have further questions or if you need help customising the sources, you are welcome to 

* → create an issue on fli4l-<revision|branch>-becto or 
* → post on news:spline.fli4l.dev or
* → contact me by mail

---
Tobias Becker, fli4l-at-becker-dot-link

__
> fli4l is a **router distribution** based on the Linux kernel which can operate
> on hardware based on at least an Intel Pentium CPU with MMX extensions
> (or compatibles). fli4l supports various protocols for upstream connections
> (e.g. ISDN, DSL, or Ethernet).
>
> The required boot media can be created under Linux or Microsoft Windows.
> Special **Linux knowledge is not required**. A basic knowledge of networking,
> however, is very helpful. Beginners should first take a look at the [Wiki](https://web.nettworks.org/wiki/display/f/fli4l-Wiki).
>
> fli4l is **highly modular**. This enables you to create a router tailored to
> your very needs. For example, you can include packages to connect networks over
> the Internet using encrypted tunnels (VPNs), to protect clients from potential
> dangers when surfing by using proxies, or to let fli4l run within a virtual
> machine (KVM, XEN). In addition, fli4l can be **easily extended** with your own
> packages. However, basic knowledge of Linux and reading the developer
> documentation is a precondition here. These extensions can then be placed
> in a central database and used by other fli4l users.
>
> fli4l can be **easily installed** on hard drives, memory cards, USB sticks,
> or compact discs.
>
> Try it out and have fun with fli4l!
> 
> -- <cite>The fli4l-Team</cite>
