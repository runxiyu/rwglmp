use fmt;
use os;
use io;
use crypto::x25519;
use crypto::random;

export fn main() void = {
	let shared_x: [32]u8 = [0...];
	let shared_y: [32]u8 = [0...];
	let priv1: [32]u8 = [0...];
	let pub1: [32]u8 = [0...];
	let priv2: [32]u8 = [0...];
	let pub2: [32]u8 = [0...];
	let seed: [32]u8 = [0...];
	random::buffer(seed);
	// fmt::print("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0")!;
	io::write(os::stdout, seed)!;
	x25519::newkey(priv1, seed);
	x25519::pubkey(pub1, priv1);
	random::buffer(seed);
	fmt::print("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0")!;
	io::write(os::stdout, seed)!;
	x25519::newkey(priv2, seed);
	x25519::pubkey(pub2, priv2);
	x25519::derive(shared_x, priv1, pub2);
	x25519::derive(shared_y, priv2, pub1);
	fmt::print("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0")!;
	io::write(os::stdout, shared_x)!;
	fmt::print("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0")!;
	io::write(os::stdout, shared_y)!;
};

