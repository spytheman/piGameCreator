package cs;

class ArrayTools {

	@:functionBody('
			return new Array<X>(native);
	')
	public static function ofNative<X>(native:NativeArray<X>):Array<X>
	{
		return null;
	}

	@:functionBody('
			return new Array<Y>(new Y[size]);
	')
	static function alloc<Y>(size:Int):Array<Y>
	{
		return null;
	}

}