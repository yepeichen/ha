// by ballypc
// Dec. 2013

#include <iostream>


#ifdef _MSC_VER
#if _MSC_VER <= 1200
namespace std {
	using ::memset;
}
#endif // _MSC_VER <= 1200
#endif // _MSC_VER


class Arranger {
public:
	Arranger (int balls, int boxes) : _balls(balls), _boxes(boxes), _arr(new int[_boxes]) {std::memset(_arr, 0, sizeof(int)*_boxes); }
	~Arranger () {delete[] _arr; }

	void arrange (void) const {this->_arrange(_arr, _balls, _boxes); }

	void arrange_noempty (void) const {this->_arrange_noempty(_arr, _balls, _boxes); }

	void arrange_order (void) const {this->_arrange_order(_arr, _balls, _boxes, _balls); }

	void arrange_order_noempty (void) const {this->_arrange_order_noempty(_arr, _balls, _boxes, _balls-_boxes+1); }

private:
	Arranger (const Arranger&);
	Arranger& operator= (const Arranger&);
	int _balls, _boxes, *_arr;

	static void _s_output(const int arr[], int len);
	void _output_arr (void) const {Arranger::_s_output(this->_arr, this->_boxes); }

	void _arrange(int arr[], int sum, int boxes) const;
	void _arrange_noempty(int arr[], int sum, int boxes) const;
	void _arrange_order(int arr[], int sum, int boxes, int max) const;
	void _arrange_order_noempty(int arr[], int sum, int boxes, int max) const;

}; // class Arranger