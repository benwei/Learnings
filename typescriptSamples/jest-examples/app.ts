
export class Memo {
	data: string;

	constructor(memo_data: string) {
	  this.data= memo_data;
	}
    static async getLatestMemo(memoId: String): Promise<any> {
	     return Promise.resolve(`This is a note of ${memoId} from asyc function definition`);
    }
}

export const handleMemo = async (): Promise<String>  => {
	const r:String = await Memo.getLatestMemo("aaa");
	return r;
}

export const getLatestMemoByConstRef = async (memoId: String): Promise<any> => {
	return Promise.resolve(`This ${memoId} is a mock from constRef`);
}
