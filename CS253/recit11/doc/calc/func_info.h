class func_info {
    public:
	func_info(fn *fn_ptr,
		  const char *key,
		  const char *description,
		  const char *(*output)(int base, number num, int width) = 0
	);
};
