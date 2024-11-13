import { StarSolid } from "@mynaui/icons-react";

interface User {
    initials: string;
    name: string;
}

interface CommentProps {
    user: User;
    date: string;
    rating: number;
    content: string;
    imageSrc?: string;
    productLink?: string;
}

function Comment({ user, date, rating, content, imageSrc, productLink }: CommentProps) {
    return (
        <div className="flex gap-4 mb-8">
            <div className="w-16 h-16 rounded-full bg-[#d1a895] flex items-center justify-center text-white text-lg font-semibold">
                {user.initials}
            </div>
            
            <div className="flex-1 flex flex-col">
                <div className="flex justify-between items-start">
                    <span className="font-semibold text-[#816c65]">{user.name}</span>
                    <span className="text-sm text-[#816c65]">{date}</span>
                </div>

                <div className="flex items-center mt-1">
                    {Array(rating).fill(null).map((_, i) => (
                        <StarSolid
                            key={i}
                            className={`h-4 w-4 ${i < rating ? "text-[#daa48a]" : "text-gray-300"}`}
                        />
                    ))}
                </div>

                <p className="text-[#816c65] mt-2">{content}</p>

                {imageSrc && (
                    <div className="mt-4">
                        <img src={imageSrc} alt="Product" className="w-24 h-24 object-cover rounded mb-2" />
                        <p className="text-sm">
                            Мнението е за продукта <a href={productLink} className="underline text-[#816c65]">WATERMELON Suntan & Body Oil</a>
                        </p>
                    </div>
                )}

                <div className="mt-4 flex justify-end text-gray-400 text-sm">
                    <span className="mr-4">Това мнение беше ли полезно за Вас?</span>
                    <button className="flex items-center gap-1">
                        👍 <span>0</span>
                    </button>
                    <button className="flex items-center gap-1 ml-2">
                        👎 <span>0</span>
                    </button>
                </div>
            </div>
        </div>
    );
}

export default Comment;
